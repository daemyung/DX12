//
// This file is part of the "dx12" project
// See "LICENSE" for license information.
//

#ifndef DX12_D3D12_RESOURCE_H_
#define DX12_D3D12_RESOURCE_H_

#include "d3d12.h"
#include "d3d12_pageable.h"

//----------------------------------------------------------------------------------------------------------------------

class D3D12Resource : public ID3D12Resource, public D3D12Pageable {
public:
    D3D12Resource(
        D3D12Device* device,
        const D3D12_HEAP_PROPERTIES* heap_properties,
        D3D12_HEAP_FLAGS heap_flags,
        const D3D12_RESOURCE_DESC* desc);

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

    D3D12_RESOURCE_DESC STDMETHODCALLTYPE GetDesc( void) override;

    D3D12_GPU_VIRTUAL_ADDRESS STDMETHODCALLTYPE GetGPUVirtualAddress( void) override;

    HRESULT STDMETHODCALLTYPE WriteToSubresource(
        UINT DstSubresource,
        _In_opt_  const D3D12_BOX *pDstBox,
        _In_  const void *pSrcData,
        UINT SrcRowPitch,
        UINT SrcDepthPitch) override;

    HRESULT STDMETHODCALLTYPE ReadFromSubresource(
        _Out_  void *pDstData,
        UINT DstRowPitch,
        UINT DstDepthPitch,
        UINT SrcSubresource,
        _In_opt_  const D3D12_BOX *pSrcBox) override;

    HRESULT STDMETHODCALLTYPE GetHeapProperties(
        _Out_opt_  D3D12_HEAP_PROPERTIES *pHeapProperties,
        _Out_opt_  D3D12_HEAP_FLAGS *pHeapFlags) override;

protected:
    D3D12_HEAP_PROPERTIES heap_properties_;
    D3D12_HEAP_FLAGS heap_flags_;
    D3D12_RESOURCE_DESC desc_;
};

//----------------------------------------------------------------------------------------------------------------------

#endif // DX12_D3D12_RESOURCE_H_
