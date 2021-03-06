//
// This file is part of the "dx12" project
// See "LICENSE" for license information.
//

#ifndef DX12_D3D12_OBJECT_H_
#define DX12_D3D12_OBJECT_H_

#include "d3d12.h"
#include "unknown.h"

//----------------------------------------------------------------------------------------------------------------------

class D3D12Object : public ID3D12Object, public Unknown {
public:
    HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        void **ppvObject) override;

    ULONG STDMETHODCALLTYPE AddRef( void) override;

    ULONG STDMETHODCALLTYPE Release( void) override;

    HRESULT STDMETHODCALLTYPE GetPrivateData(
        _In_  REFGUID guid,
        _Inout_  UINT *pDataSize,
        _Out_writes_bytes_opt_( *pDataSize )  void *pData) override;

    HRESULT STDMETHODCALLTYPE SetPrivateData(
        _In_  REFGUID guid,
        _In_  UINT DataSize,
        _In_reads_bytes_opt_( DataSize )  const void *pData) override;

    HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        _In_  REFGUID guid,
        _In_opt_  const IUnknown *pData) override;

    HRESULT STDMETHODCALLTYPE SetName(
        _In_z_  LPCWSTR Name) override;
};

//----------------------------------------------------------------------------------------------------------------------

#endif // DX12_D3D12_OBJECT_H_
