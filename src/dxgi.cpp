//
// This file is part of the "dx12" project
// See "LICENSE" for license information.
//

#include "dxgi.h"

#include "dxgi_factory.h"

//----------------------------------------------------------------------------------------------------------------------

HRESULT WINAPI CreateDXGIFactory(REFIID riid, _COM_Outptr_ void **ppFactory)
{
    *ppFactory = new DXGIFactory();
    
    return S_OK;
}

//----------------------------------------------------------------------------------------------------------------------
