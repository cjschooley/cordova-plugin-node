//
//  VIChromaMatch.h
//  Node
//
//  Created by Wade Gasior on 3/13/14.
//  Copyright (c) 2014 Variable, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Node.h"

#import "VIChromaSession.h"
#import "VIChromaMatchLibrary.h"
#import "VIChromaMatchExternalLibrary.h"

@interface VIChromaMatch : NSObject

typedef void (^ ColorApiKeySucessBlock)(VIChromaSession *accountStatus);
typedef void (^ ColorApiKeyFailBlock)(NSError *error);

#define ColorApiKeyRegistrationErrorGeneral                  1
#define ColorApiKeyRegistrationErrorGeneralMsg               @"There was an error registering the API Key."
#define ColorAppApiKeyRegistrationErrorDisabled              2
#define ColorAppApiKeyRegistrationErrorDisabledMsg           @"The provided API Key is not enabled."
#define ColorApiKeyRegistrationErrorCodeTooShort             3
#define ColorApiKeyRegistrationErrorCodeTooShortMsg          @"The provided code was too short."
#define ColorApiKeyRegistrationErrorNoWeb                    4
#define ColorApiKeyRegistrationErrorNoWebMsg                 @"No internet connection detected."
#define ColorApiKeyRegistrationErrorNotValid                 5
#define ColorApiKeyRegistrationErrorNotValidMsg              @"The provided color library key is not valid."
#define ColorApiKeyRegistrationErrorDisabled                 6
#define ColorApiKeyRegistrationErrorDisabledMsg              @"The provided color library key is not enabled."

/** Fetch all available Libraries accessible to account
 @return An array of VIChromaMatchColorLibraries objects
 */
+(NSArray *)fetchAllLibraries;

/** Fetch Library object for a given ID (if account has access)
 @param webId ID for Color Library
 @return VIChromaMatchLibrary object
 */
+(VIChromaMatchLibrary*)fetchLibrary:(int)webId;

/** Fetch all available Materials/TextureTypes associated with Libraries
 @return An array of material names (NSStrings)
 */
+(NSArray*)fetchAllMaterials;

/** Fetch Dictionary of all Materials(as keys) associated to their Libraries
 @return An Dictionary @{"materialName": @{"ColorLibraries":@[VIChromaMatchLibrary],"ExternalLibraries":@[VIChromaMatchExtLibs]}}
 */
+(NSDictionary*)fetchMaterialsToLibraries;

/** Fetch all available Country Regions associated with Libraries
 @return An array of country names (NSStrings)
 */
+(NSArray *)fetchAllCountries;

/** Fetch all available Libraries accessible to account and a Country
 @return An array of VIChromaMatchColorLibraries objects
 */
+(NSArray *)fetchAllLibrariesInCountry:(NSString*)country;


/** Fetch External Libraries (if account has access)
 @param completion Asynchronously provides array of VIChromaMatchExternalLibrary objects
 @param errorBlock Asynchronously provides feedback upon error
 */
+(void)fetchAllExternalLibraries:(void(^)(NSArray *libs))completion onError:(ColorApiKeyFailBlock)errorBlock;


/**
 Request a Chroma match reading
 @param libs NSArray of VIChromaMatchLibrary objects from which to match
 @param serial A valid serial for a ChromaDevice to use for color math
 @param reading The VIColorReading to use in the match
 */
+(void)requestChromaMatchReadingUsingLibraries: (NSArray *)libs
                                  chromaSerial: (NSString*)serial
                                       reading: (VIColorReading*)reading
                                      onResult: (void (^)(NSArray *results, NSString *eventUUID))onResult;

/**
 Request a Chroma match reading
 @param libs NSArray of VIChromaMatchLibrary objects from which to match
 @param serial A valid serial for a ChromaDevice to use for color math
 @param reading The VIColorReading to use in the match
 */
+(void)requestChromaMatchReadingUsingLibraries: (NSArray *)libs
                                  chromaSerial: (NSString *)serial
                                       reading: (VIColorReading *)reading
                             withAnalyticsData: (NSDictionary *)analyticsData
                                      onResult: (void (^)(NSArray *, NSString *))onResult;


/**
 Request Chroma match results based on a library swatch
 @param libs NSArray of VIChromaMatchLibrary objects from which to match
 @param swatch The VIChromaMatchSwatch to use in the match
 @param onResult callback block providing array of VIChromaMatchResults and an event UUID
 */
+(void)requestChromaMatchReadingUsingLibraries: (NSArray *)libs
                                    fromSwatch:(VIChromaMatchSwatch*)swatch
                                      onResult: (void (^)(NSArray *results, NSString *eventUUID))onResult;


/**
 Request a Chroma match reading from a specfic library
 @param libs NSArray of VIChromaMatchLibrary objects from which to match
 @param lab The VTLabColor to use in the match
 @param batch Batch# of a ChromaDevice
 */
+ (void) requestChromaMatchReadingUsingLibraries: (NSArray *)libs
                                    fromLabColor: (VTLabColor *)lab
                                  forChromaBatch: (NSNumber *)batch
                                        onResult: (void (^)(NSArray *results, NSString *eventUUID))onResult;

/**
 Request a Chroma match reading across all loaded color sets
 @param libs NSArray of VIChromaMatchLibrary objects from which to match
 @param lab The VTLabColor to use in the match
 @param batch Batch# of a ChromaDevice
 */
+ (void) requestChromaMatchReadingUsingLibraries: (NSArray *)libs
                                    fromLabColor: (VTLabColor *)lab
                                  forChromaBatch: (NSNumber *)batch
                               withAnalyticsData: (NSDictionary *)analyticsData
                                        onResult: (void (^)(NSArray *results, NSString *eventUUID))onResult;

/**
 Request a Chroma match reading across all loaded color sets
 @param libs NSArray of VIChromaMatchLibrary objects from which to match
 @param rgb The VTRGBColor to use in the match
 @param batch Batch# of a ChromaDevice
 */
+ (void) requestChromaMatchReadingUsingLibraries: (NSArray *)libs
                                    fromRGBColor: (VTRGBColor *)rgb
                               withAnalyticsData: (NSDictionary *)analyticsData
                                        onResult: (void (^)(NSArray *results, NSString *eventUUID))onResult;

+(VTLabColor *) requestRepresentativeLabFromSwatch: (VIChromaMatchSwatch*)swatch usingIll: (VTColorUtilsIlluminant)illum;

/**
 Request A Silent Update of Accounts Associated with this App
 */
+(void)updateApiKeysInBG;

/**
 Synchronously Updates Registered Accounts
 */
+(void)updateApiKeys;

@end
