/*
 * Profinet_decode.c
 *
 *  Created on: 2015��6��15��
 *      Author: zwj, dl
 */

#ifndef Profinet_DECODE_H
#define Profinet_DECODE_H

#include <linux/types.h>


#include <linux/skbuff.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/ipv6.h>
#include <linux/netfilter/x_tables.h>
#include <linux/types.h>
#include <linux/netfilter.h>
#include <linux/version.h>
#include <linux/netfilter_ipv4.h>
#include <linux/moduleparam.h>
#include <linux/netfilter_ipv4/ip_tables.h>
#include <linux/init.h>
#include <linux/inet.h>
#define Profinet_OK 1
#define Profinet_FAIL (-1)

/* Need 8 bytes for MBAP Header + Function Code */
#define Profinet_MIN_LEN 5

/* GIDs, SIDs, and Strings */
#define GENERATOR_SPP_Profinet 144

#define Profinet_BAD_LENGTH 1
#define Profinet_BAD_PROTO_ID 2
#define Profinet_RESERVED_FUNCTION 3

#define Profinet_BAD_LENGTH_STR "(spp_Profinet): Length in Profinet MBAP header does not match the length needed for the given Profinet function."
#define Profinet_BAD_PROTO_ID_STR "(spp_Profinet): Profinet protocol ID is non-zero."
#define Profinet_RESERVED_FUNCTION_STR "(spp_Profinet): Reserved Profinet function code in use."

#define Profinet_DATA_LEN_OK									1
#define Profinet_DATA_LEN_FAIL								0

#define Profinet_PORT_OK									1
#define Profinet_PORT_FAIL								0

#define Profinet_IP_OK									1
#define Profinet_IP_FAIL								0

#define FROM_CLIENT_FLAG		0
#define FROM_SERVER_FLAG		1

#define Profinet_FUNCODE_REJECT      0
#define Profinet_FUNCODE_RECEIVE	 1

#define THIS_IS_REJECT_FUN_CODE 		 1
#define THIS_IS_NOT_REJECT_FUN_CODE 	 0
struct xt_Profinet_mtinfo {
	__u32 src_port;
	__u32 dst_port;	
    __u8 flags;
};

int ProfinetDecode(char *app_data, __u16 app_len, __u8 flags, const struct xt_Profinet_mtinfo *info, const struct sk_buff *skb);
#endif /* Profinet_DECODE_H */
