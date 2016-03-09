//
//  VIColorReading.h
//  B2ChromaScanner
//
//  Created by Andrew T on 5/8/15.
//  Copyright (c) 2015 Variable Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VTColorUtils.h"
#import "VTLabColor.h"
#import "VTXYZColor.h"
#import "VTRGBColor.h"


@class VIChromaSensorReading;

@interface VIColorReading : NSObject
 @property (strong, nonatomic) VIChromaSensorReading *sense;
 @property (strong, nonatomic) VTXYZColor *unadjD65XYZ;
 @property (strong, nonatomic) VTXYZColor *adjD65XYZ;
 @property (strong, nonatomic, readonly) NSDictionary *json;

 /** Get a Tristimulus Color Value (XYZ)
 @param illuminant D50 or D65 reference illuminant (D50 is default for Color Match)
 @param observer 2˚ or 10˚ Observer. (Default is 2˚)
 @param adjusted Specify to use fine tuning color adjustment for most accurate #. (Default is true)
 @return A VTXYZColor Tristimulus Color object (XYZ)
 */
 -(VTXYZColor*)getXYZ:(VTColorUtilsIlluminant)illuminant observer:(VTColorUtilsObserver)observer adjusted:(BOOL)adjusted;

 /** Get a CIE Lab Color Value
 @param illuminant D50 or D65 reference illuminant (D50 is default for Color Match)
 @param observer 2˚ or 10˚ Observer. (Default is 2˚)
 @param adjusted Specify to use fine tuning color adjustment for most accurate #. (Default is true)
 @return A VTLabColor CIE Lab Color object
 */
 -(VTLabColor*)getLab:(VTColorUtilsIlluminant)illuminant observer:(VTColorUtilsObserver)observer adjusted:(BOOL)adjusted;

 /** Get Sense Value Array (RGBC)
 @return An NSArray of the sense values from VIChromaSensorReading used to build this object
 */
 -(NSArray*)getRGBCArray;

 /** Get UIColor Object
 @return A UIColor object based on the fine-tuned/adjusted VIColorReading in sRGB
 */
 -(UIColor*)displayColor;


/** Get the Chroma Serial #
 @return NSString of the Chroma serial # used to take the ColorReading
 */
-(NSString*)getSerial;

/** Get the Chroma's Production Batch #
 @return int of the Chroma production batch #
 */
-(int)getBatchNumber;

@end


@interface VIChromaSensorReading : NSObject
 @property uint16_t senseClear, senseRed, senseGreen, senseBlue;

 /** Init VIChromaSensorReading
 @param redSense Chroma Modules raw sensor reading channel.
 @param greenSense Chroma Modules raw sensor reading channel.
 @param blueSense Chroma Modules raw sensor reading channel.
 @param clearSense Chroma Modules raw sensor reading channel.
 @return A VIChromaSensorReading object
 */
 -(id)initWithR:(uint16_t)redSense g:(uint16_t)greenSense b:(uint16_t)blueSense c:(uint16_t)clearSense;

 /** Get a valid Color Reading Object. (REQUIREDS the Chroma Device to be registered w/ chromaInitWithAppKey:)
 @param observer 2˚ or 10˚ Observer (Default is 2˚)
 @param serial Chroma Module Serial # !!! that HAS BEEN REGISTERED using VTNodeDevice:chromaInitWithAppKey: !!!
 @return A VIColorReading object
 */
 -(VIColorReading*)toColorReading:(VTColorUtilsObserver)observer chromaSerial:(NSString*)serial;

@end