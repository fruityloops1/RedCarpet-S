#!/usr/bin/env python3

import argparse
import hashlib
from pathlib import Path
import subprocess
import tempfile
import urllib.request
from typing import Optional
from common import setup_common as setup


TARGET_PATH = setup.get_target_path()
TARGET_ELF_PATH = setup.get_target_elf_path()

def prepare_executable(original_nso: Optional[Path]):
    COMPRESSED_V110_HASH = "98df053831017d4607cd4285ffd622e3e9183f5976ca020c1701cb781907ca0e"
    UNCOMPRESSED_V110_HASH = "be1917470961c50b1ebe7e07c2d874f2abb16f98ad8054ac2d5ff8e0422f8f7f"

    # The uncompressed v1.1.0 main NSO.
    TARGET_HASH = UNCOMPRESSED_V110_HASH

    if TARGET_PATH.is_file() and hashlib.sha256(TARGET_PATH.read_bytes()).hexdigest() == TARGET_HASH and TARGET_ELF_PATH.is_file():
        print(">>> NSO is already set up")
        return

    if original_nso is None:
        setup.fail("please pass a path to the NSO (refer to the readme for more details)")

    if not original_nso.is_file():
        setup.fail(f"{original_nso} is not a file")

    nso_data = original_nso.read_bytes()
    nso_hash = hashlib.sha256(nso_data).hexdigest()

    if nso_hash == UNCOMPRESSED_V110_HASH:
        print(">>> found uncompressed 1.1.0 NSO")
        TARGET_PATH.write_bytes(nso_data)

    elif nso_hash == COMPRESSED_V110_HASH:
        print(">>> found compressed 1.1.0 NSO")
        setup._decompress_nso(original_nso, TARGET_PATH)

    else:
        setup.fail(f"unknown executable: {nso_hash}")

    if not TARGET_PATH.is_file():
        setup.fail("internal error while preparing executable (missing NSO); please report")
    if hashlib.sha256(TARGET_PATH.read_bytes()).hexdigest() != TARGET_HASH:
        setup.fail("internal error while preparing executable (wrong NSO hash); please report")

    setup._convert_nso_to_elf(TARGET_PATH)

    if not TARGET_ELF_PATH.is_file():
        setup.fail("internal error while preparing executable (missing ELF); please report")


def create_build_dir():
    build_dir = setup.ROOT / "build"
    if build_dir.is_dir():
        print(">>> build directory already exists: nothing to do")
        return

    subprocess.check_call(
        "cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_TOOLCHAIN_FILE=toolchain/ToolchainNX64.cmake -DCMAKE_CXX_COMPILER_LAUNCHER=ccache -B build/".split(" "))
    print(">>> created build directory")


def main():
    parser = argparse.ArgumentParser(
        "setup.py", description="Set up the Super Mario 3D World + Bowser's Fury decompilation project")
    parser.add_argument("original_nso", type=Path,
                        help="Path to the original NSO (1.1.0, compressed or not)", nargs="?")
    args = parser.parse_args()

    setup.install_viking()
    prepare_executable(args.original_nso)
    setup.set_up_compiler("8.0.0")
    create_build_dir()


if __name__ == "__main__":
    main()
