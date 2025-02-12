/*
 * SPDX-FileCopyrightText: 2015-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <stdbool.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Init LCD
 * 
 * @return
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t bsp_lcd_init(void);

/**
 * @brief Deinit LCD
 * 
 * @return 
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t bsp_lcd_deinit(void);

/**
 * @brief Flush LCD
 * 
 * @param x1 Start index on x-axis (x1 included)
 * @param y1 Start index on y-axis (y1 included)
 * @param x2 End index on x-axis (x2 not included)
 * @param y2 End index on y-axis (y2 not included)
 * @param p_data RGB color data that will be dumped to the specific range
 * @return 
 *    - ESP_OK: Success
 *    - ESP_ERR_TIMEOUT: Timeout waiting for previous transaction finished
 *    - Others: Fail
 */
esp_err_t bsp_lcd_flush(int x1, int y1, int x2, int y2, const void *p_data);

/**
 * @brief Set callback function when a single flush transaction is finished
 * 
 * @param trans_done_cb Callback function
 * @param data User data
 * @return 
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t bsp_lcd_set_cb(bool (*trans_done_cb)(void *), void *data);

/**
 * @brief Deinit LCD with SPI interface
 * 
 * @return 
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t bsp_spi_lcd_deinit(void);

/**
 * @brief Set backlight
 * 
 * @param en 0: OFF, other: ON
 * 
 * @return 
 *    - ESP_OK: Success
 *    - Others: Fail
 */
esp_err_t bsp_lcd_set_backlight(bool en);

#ifdef __cplusplus
}
#endif
