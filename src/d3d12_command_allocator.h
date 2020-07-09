//
// This file is part of the "dx12" project
// See "LICENSE" for license information.
//

#ifndef DX12_D3D12_COMMAND_ALLOCATOR_H_
#define DX12_D3D12_COMMAND_ALLOCATOR_H_

#include "d3d12.h"
#include "d3d12_pageable.h"
#include "metal_library.h"

//----------------------------------------------------------------------------------------------------------------------

class D3D12CommandAllocator : public ID3D12CommandAllocator, public D3D12Pageable {
public:
    D3D12CommandAllocator(D3D12Device* device_ptr);

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

    HRESULT STDMETHODCALLTYPE Reset( void) override;

    id<MTLCommandBuffer> GetCommandBuffer() const;

private:
    id<MTLCommandBuffer> command_buffer_ = { nil };
};

//----------------------------------------------------------------------------------------------------------------------

#endif
