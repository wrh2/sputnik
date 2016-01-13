/*
	SPI driver for the Freescale MKW01 internal SPI module (aka SPI0).
	This module is special because it is solely dedicated for communicating
	with the integrated transceiver which isn't really integrated..

	Programmed by William Harrington, Theo Hill
*/
#include <stdbool.h>
#include <stdint.h>

#include "kw0x.h"

/* struct for pin selection */
struct pin {
	volatile struct port * port; /* port module */
	uint8_t pin; /* pin on port module */
};

/* struct for specifying config */
struct spi_config {
	struct pin SCK; /* clock */
	struct pin SS; /* slave select */
	struct pin MOSI; /* master out, slave in */
	struct pin MISO; /* master in, slave out */
	bool CPOL; /* clock polarity */
	bool CPHA; /* clock phase */
};

/* initialization function */
void spi_init(struct spi * SPI, const struct spi_config * config);

/* read function */
void spi_read(struct spi * SPI, size_t len, uint16_t * buffer);

/* write function */
void spi_write(struct spi * SPI, size_t len, uint16_t * buffer);

/* SPI transaction frame */
void spi_transaction(struct spi * SPI, size_t len, uint16_t * sendBuffer, uint16_t * recvBuffer);