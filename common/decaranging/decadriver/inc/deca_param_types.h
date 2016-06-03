/*! ----------------------------------------------------------------------------
 *  @file    deca_param_types.h
 *  @brief   DecaWave general type definitions for configuration structures
 *
 * @attention
 *
 * Copyright 2013 (c) DecaWave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 * @author DecaWave
 */
#ifndef _DECA_PARAM_TYPES_H_
#define _DECA_PARAM_TYPES_H_

// includes
#include <stdint.h>

#define NUM_BR 		3
#define NUM_PRF 	2
#define NUM_PACS 	4
#define NUM_BW 		2 //2 bandwidths are supported
#define NUM_SFD 	2	//supported number of SFDs - standard = 0, non-standard = 1
#define NUM_CH 		6 //supported channels are 1, 2, 3, 4, 5, 7
#define NUM_CH_SUPPORTED 8 //supported channels are '0', 1, 2, 3, 4, 5, '6', 7
#define PCODES 		25 //supported preamble codes


typedef struct {
		uint32_t lo32;
		uint16_t target[NUM_PRF];
} agc_cfg_struct ;

extern const agc_cfg_struct agc_config ;

//SFD threshold settings for 110k, 850k, 6.8Mb standard and non-standard
extern const uint16_t sftsh[NUM_BR][NUM_SFD]; 
extern const uint16_t dtune1[NUM_PRF];

#define XMLPARAMS_VERSION	(1.17f)

extern const uint8_t 	pll2_config[NUM_CH][5];
extern const uint8_t 	pll2calcfg;
extern const uint8_t 	rx_calibration[NUM_BW];
extern const uint32_t 	tx_calibration[NUM_CH];
extern const uint8_t 	dwnsSFDlen[NUM_BR];
extern const uint32_t 	digital_bb_config[NUM_PRF][NUM_PACS];
extern const uint8_t 	chan_idx[NUM_CH_SUPPORTED];

#define PEAK_MULTPLIER 	(0x60)	//3 -> (0x3 * 32) & 0x00E0 
#define N_STD_FACTOR 	(13)
#define LDE_PARAM1		(PEAK_MULTPLIER | N_STD_FACTOR)

#define LDE_PARAM3_16 (0x1607)
#define LDE_PARAM3_64 (0x0607)

extern const uint16_t lde_replicaCoeff[PCODES];

#endif


