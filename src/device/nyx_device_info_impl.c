/* @@@LICENSE
*
*      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */

/**
 *******************************************************************************
 * @file nyx_device_info_impl.c
 *
 * @brief implementation of NYX's public API for accessing device information
 *
 *******************************************************************************
 */

#include "nyx_device_info_impl.h"

nyx_error_t nyx_device_info_get_info(nyx_device_handle_t handle, nyx_device_info_type_t type, char* dest, size_t dest_len)
{
	nyx_execute_return_function(device_info_get_info, DEVICE_INFO, GET_INFO, handle, type, dest, dest_len);
}

nyx_error_t nyx_device_info_get_hardware_id(nyx_device_handle_t handle, int32_t* out_hw_id)
{
	nyx_device_t* d = (nyx_device_t*)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_DEVICE_INFO);
	nyx_device_info_device_t* dev = (nyx_device_info_device_t*)d;
	*out_hw_id = dev->hardware_id;
	return NYX_ERROR_NONE;
}

