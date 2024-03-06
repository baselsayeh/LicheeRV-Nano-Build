// Copyright 2017-2019 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _SSV_FAST_PROV_OPERATION_H
#define _SSV_FAST_PROV_OPERATION_H

#include "ssv_fast_prov_common.h"

ssv_err_t example_store_node_info(const uint8_t uuid[16], uint16_t node_addr,
                                  uint8_t elem_num, uint16_t net_idx,
                                  uint16_t app_idx, uint8_t onoff);

example_node_info_t *example_get_node_info(uint16_t node_addr);

bool example_is_node_exist(const uint8_t uuid[16]);

uint16_t example_get_node_address(int node_idx);

ssv_ble_mesh_model_t *example_find_model(uint16_t element_addr, uint16_t model_id,
        uint16_t company_id);

ssv_err_t example_handle_config_app_key_add_evt(uint16_t app_idx);

ssv_err_t example_add_fast_prov_group_address(uint16_t model_id, uint16_t group_addr);

ssv_err_t example_delete_fast_prov_group_address(uint16_t model_id, uint16_t group_addr);

ssv_err_t example_send_config_appkey_add(ssv_ble_mesh_model_t *model,
        example_msg_common_info_t *info,
        ssv_ble_mesh_cfg_app_key_add_t *add_key);

ssv_err_t example_send_generic_onoff_get(ssv_ble_mesh_model_t *model,
        example_msg_common_info_t *info);

ssv_err_t example_send_generic_onoff_set(ssv_ble_mesh_model_t *model,
        example_msg_common_info_t *info,
        uint8_t onoff, uint8_t tid, bool need_ack);

ssv_err_t example_send_fast_prov_info_set(ssv_ble_mesh_model_t *model,
        example_msg_common_info_t *info,
        example_fast_prov_info_set_t *set);

ssv_err_t example_send_fast_prov_net_key_add(ssv_ble_mesh_model_t *model,
        example_msg_common_info_t *info,
        uint8_t net_key[16]);

ssv_err_t example_send_fast_prov_self_prov_node_addr(ssv_ble_mesh_model_t *model,
        example_msg_common_info_t *info,
        struct net_buf_simple *node_addr);

ssv_err_t example_send_fast_prov_all_node_addr_get(ssv_ble_mesh_model_t *model,
        example_msg_common_info_t *info);

ssv_err_t example_send_fast_prov_status_msg(ssv_ble_mesh_model_t *model,
        ssv_ble_mesh_msg_ctx_t *ctx,
        uint32_t opcode, struct net_buf_simple *msg);

#endif /* _SSV_FAST_PROV_OPERATION_H */