//
// This file is part of the "dx12" project
// See "LICENSE" for license information.
//

#ifndef DX12_D3D12_DEVICE_CHILD_H_
#define DX12_D3D12_DEVICE_CHILD_H_

#include "d3d12.h"
#include "d3d12_object.h"

//----------------------------------------------------------------------------------------------------------------------

class D3D12Device;

//----------------------------------------------------------------------------------------------------------------------

class D3D12DeviceChild : public ID3D12DeviceChild, public D3D12Object {
public:
    D3D12DeviceChild(D3D12Device* device);

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

    HRESULT STDMETHODCALLTYPE GetDevice(
        REFIID riid,
        _COM_Outptr_opt_  void **ppvDevice) override;

protected:
    D3D12Device* device_ = { nullptr };
};

//----------------------------------------------------------------------------------------------------------------------

#endif // DX12_D3D12_DEVICE_CHILD_H_
