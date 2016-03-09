//
//  VIAnalytics.h
//  Node_iOS
//
//  Created by Wade Gasior on 7/30/15.
//  Copyright (c) 2015 Variable, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

//Analytic Events
#define VIANAEVENT_CHROMA_SCAN                    @"chroma-scan"
#define VIANAEVENT_CHROMA_MATCH                   @"chroma-match"
#define VIANAEVENT_CHROMA_MATCH_RD_SER            @"chroma-match-from-reading-and-serial"
#define VIANAEVENT_CHROMA_MATCH_LAB               @"chroma-match-from-lab"
#define VIANAEVENT_CHROMA_MATCH_RGB               @"chroma-match-from-rgb"

//Analytic Properties
#define VIANAKEY_VI_COLOR_READING               @"vi-color-reading"
#define VIANAKEY_UNADJUSTED_D50_LAB             @"unadjusted-d50-lab"
#define VIANAKEY_LAB_FOR_MATCH                  @"unadjusted-d50-lab-for-match"
#define VIANAKEY_PARENT_EVENT_UUID              @"parent-event-uuid"
#define VIANAKEY_CHROMA_SERIAL                  @"chroma-serial"
#define VIANAKEY_B2_LIB_ID                      @"b2-chroma-match-lib-id"
#define VIANAKEY_CLOSEST_MATCHES                @"closest-matches"
#define VIANAKEY_CHROMA_BATCH                   @"chroma-batch"
#define VIANAKEY_RGB_FOR_MATCH                  @"rgb-for-match"


@interface VIAnalytics : NSObject

+ (void) logEvent: (NSString *)event withParameters: (NSDictionary *)params
        onSuccess: (void (^)(NSString *uuid, NSDictionary *eventData))onSuccessCallback
          onError: (void (^)(NSError *))onErrorCallback;

//Set user account - this will be sent with every event
+ (void) setUserAccount: (NSString *)account;

//Set extra analytics info that will be sent with every event
+ (void) setExtraAnalyticsInfo: (NSDictionary *)info;

@end
