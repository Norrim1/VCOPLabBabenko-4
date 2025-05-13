#pragma once
#include <objbase.h>
#include <iostream>

extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IID_IZ;
extern const IID IID_IUnknown;

interface IX : IUnknown {
    virtual void __stdcall Fx() = 0;
};

interface IY : IUnknown {
    virtual void __stdcall Fy() = 0;
};

interface IZ : IUnknown {
    virtual void __stdcall Fz() = 0;
};

class CA : public IX, public IY {
    public:
        virtual ULONG __stdcall AddRef();
        virtual ULONG __stdcall Release();
        virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
        virtual void __stdcall Fx();
        virtual void __stdcall Fy();
};

IUnknown* CreateInstance();

void f(IX* pIX);
void f2(IX* pIX);
void f3(IX* pIX);
BOOL SameComponents(IX* pIX, IY* pIY);
