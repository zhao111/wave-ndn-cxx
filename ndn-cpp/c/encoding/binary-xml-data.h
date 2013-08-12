/**
 * @author: Jeff Thompson
 * See COPYING for copyright and distribution information.
 */

#ifndef NDN_BINARY_XML_DATA_H
#define NDN_BINARY_XML_DATA_H

#include "../errors.h"
#include "../data.h"
#include "binary-xml-encoder.h"
#include "binary-xml-decoder.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Encode the data packet as binary XML.
 * @param data Pointer to the data object to encode.
 * @param signedFieldsBeginOffset Return the offset in the encoding of the beginning of the fields which are signed.
 * If you are not encoding in order to sign, you can ignore this returned value.
 * @param signedFieldsEndOffset Return the offset in the encoding of the end of the fields which are signed.
 * If you are not encoding in order to sign, you can ignore this returned value.
 * @param encoder Pointer to the ndn_BinaryXmlEncoder struct which receives the encoding. 
 * @return 0 for success, else an error code.
 */
ndn_Error ndn_encodeBinaryXmlData
  (struct ndn_Data *data, unsigned int *signedFieldsBeginOffset, unsigned int *signedFieldsEndOffset, struct ndn_BinaryXmlEncoder *encoder);

/**
 * Decode the data packet as binary XML and set the fields in the data object.
 * @param data Pointer to the data object whose fields are updated.
 * @param signedFieldsBeginOffset Return the offset in the input buffer of the beginning of the fields which are signed.
 * If you are not decoding in order to verify, you can ignore this returned value.
 * @param signedFieldsEndOffset Return the offset in the input buffer of the end of the fields which are signed.
 * If you are not decoding in order to verify, you can ignore this returned value.
 * @param decoder Pointer to the ndn_BinaryXmlDecoder struct which has been initialized with the buffer to decode. 
 * @return 0 for success, else an error code.
 */
ndn_Error ndn_decodeBinaryXmlData
  (struct ndn_Data *data, unsigned int *signedFieldsBeginOffset, unsigned int *signedFieldsEndOffset, struct ndn_BinaryXmlDecoder *decoder);

#ifdef __cplusplus
}
#endif

#endif
