#pragma once

#include "al/Layout/LayoutActor.h"
#include "al/Layout/LayoutInitInfo.h"

class WindowMessage : public al::LayoutActor {
    void* _120 = nullptr;
    const char16_t* mMessage = nullptr;
    int _130;
    int mPageAmount;
    int mPageIndex;
    int _13C;

public:
    WindowMessage(const al::LayoutInitInfo& pInfo, const char* pArchiveName, const char* pName, const char* = nullptr);

    void appearWithSystemMessage(const char* pMessageBinary, const char* pMsg, int);
    void appearWithSingleMessage(const char16_t* pMsg);

    void exeAppear();
    void exeWait();
};
