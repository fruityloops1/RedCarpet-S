from git import Repo, Commit
import csv
from io import StringIO
import subprocess

import datetime
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.ticker

subprocess.call(["tools/check"])
subprocess.call(["tools/common/progress.py"])

repo = Repo(".")

def isCommitInCsv(data: str):
    if str(repo.commit()) in data:
        return True

# add current progress if not present

file = open("data/progress_history.csv", 'r')
data = str(file.read())
file.close()
if not isCommitInCsv(data):
    appendData = subprocess.check_output(["tools/common/progress.py", "--csv"]).decode('utf-8')
    file = open("data/progress_history.csv", "a")
    file.write(appendData)
    file.close()
    data += appendData

def getCommit(hash: Commit):
    reader = csv.reader(StringIO(data), delimiter=',', quotechar='"')
    for row in reader:
        if row[2] == str(hash):
            return row
    return None

def getCurrentCommit():
    reader = csv.reader(StringIO(subprocess.check_output(["tools/common/progress.py", "--csv"]).decode('utf-8')), delimiter=',', quotechar='"')
    for row in reader:
        return row
    return None

cur_commit = getCurrentCommit()

x_values = [datetime.datetime.now()]
y_values = [(int(cur_commit[5]) / int(cur_commit[3])) * 100]

for commit in repo.iter_commits():
    x_values.append(datetime.datetime.fromtimestamp(commit.committed_date))
    commit_data = getCommit(commit)
    y_values.append((int(commit_data[5]) / int(commit_data[3])) * 100)

fig,ax = plt.subplots()

dates = matplotlib.dates.date2num(x_values)
ax.set_title("Matching")
ax.xaxis.set_major_formatter(matplotlib.dates.ConciseDateFormatter(ax.xaxis.get_major_locator()))
ax.yaxis.set_major_formatter(matplotlib.ticker.PercentFormatter())
ax.plot_date(dates, y_values, '-')

plt.savefig("data/progress.png")