/*
 *
 * Copyright (C) 2022, Broadband Forum
 * Copyright (C) 2022, Snom Technology GmbH
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * \file usp_record.h
 *
 * Header file for USP Record definitions and helpers
 *
 */
#ifndef USP_RECORDS_H
#define USP_RECORDS_H

#include "common_defs.h"
#include "usp-record.pb-c.h"
#include "mqtt.h"
#if defined(E2ESESSION_EXPERIMENTAL_USP_V_1_2)
#include "e2e_defs.h"
#endif

//------------------------------------------------------------------------------
// Structure containing common elements about USP Message to send
typedef struct
{
    Usp__Header__MsgType usp_msg_type;  // USP Message type (For log usage only)
    uint8_t *msg_packed;                // Protobuf encoded USP Message to be encapsulate in USP Record
    int msg_packed_size;                // Length of the payload
#if defined(E2ESESSION_EXPERIMENTAL_USP_V_1_2)
    e2e_session_t *curr_e2e_session;    // Associated E2E session values
#endif
} usp_send_item_t;

//------------------------------------------------------------------------------
// API
UspRecord__Record *USPREC_WebSocketConnect_Create(void);
UspRecord__Record *USPREC_MqttConnect_Create(mqtt_protocolver_t version, char* topic);
UspRecord__Record *USPREC_StompConnect_Create(char* destination);
UspRecord__Record *USPREC_Disconnect_Create(uint32_t reason_code, char* reason_str);
void USPREC_UspSendItem_Init(usp_send_item_t *usi);

#endif