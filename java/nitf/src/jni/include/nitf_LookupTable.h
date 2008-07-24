/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program; if not, If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 */

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <import/nitf.h>
/* Header for class nitf_LookupTable */

#ifndef _Included_nitf_LookupTable
#define _Included_nitf_LookupTable
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     nitf_LookupTable
 * Method:    construct
 * Signature: (II[B)V
 */
JNIEXPORT void JNICALL Java_nitf_LookupTable_construct
  (JNIEnv *, jobject, jint, jint, jbyteArray);

/*
 * Class:     nitf_LookupTable
 * Method:    destructMemory
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nitf_LookupTable_destructMemory
  (JNIEnv *, jobject);

/*
 * Class:     nitf_LookupTable
 * Method:    getNumTables
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_nitf_LookupTable_getNumTables
  (JNIEnv *, jobject);

/*
 * Class:     nitf_LookupTable
 * Method:    getNumEntries
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_nitf_LookupTable_getNumEntries
  (JNIEnv *, jobject);

/*
 * Class:     nitf_LookupTable
 * Method:    getData
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_nitf_LookupTable_getData
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
