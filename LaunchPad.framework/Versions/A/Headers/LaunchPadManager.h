//
//  LaunchPadManager.h
//  LaunchPad
//
//  Copyright (c) 2013 Syrp Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LPElementProtocol.h"
#import "LPProperties.h"

typedef enum {
    LPDev,
    LPProduction,
    LPLocalHost
} LPServer;

@protocol LaunchPadDelegate <NSObject>

- (void)launchPadUpdated;

- (void)launchPadThemeChanged:(NSString*)themeName;

@end

@interface LaunchPadManager : NSObject

@property (nonatomic, weak) id<LaunchPadDelegate> delegate;
@property (nonatomic) BOOL isLoadingProperties;
@property (nonatomic) BOOL liveUpdate;
// Loaded Side Step Properties
@property (nonatomic, strong) LPProperties* lpProperties;
@property (nonatomic) LPServer lpServer;

// Get Singleton LaunchPadManager Object
+ (LaunchPadManager*)sharedManager;

// Start LaunchPad With API Key Methods
+ (void)startLaunchPadAPIKey:(NSString*)apiKey liveUpdate:(BOOL)liveUpdate;

+ (void)startLaunchPadAPIKey:(NSString*)appID server:(LPServer)server liveUpdate:(BOOL)liveUpdate;

// Element Life Cycle Methods
- (void)elementInit:(id<LPElementProtocol>)element;

- (void)elementDealloc:(id<LPElementProtocol>)element;

- (void)element:(id<LPElementProtocol>)element setState:(NSString*)stateName;

// Change the LaunchPad Server
- (void)setLPServer:(LPServer)server;

// Setting Element Property Values
- (BOOL)setValueInElement:(NSObject*)element lpElement:(id<LPElementProtocol>)lpElement fromValue:(id)value key:(NSString *)key;

- (void)setValuesInElement:(NSObject<LPElementProtocol>*)element propertiesDic:(NSDictionary*)propertiesDic;

- (void)checkLoadedElementsWithNewProperties;

// Setting ViewController Appearance
- (void)setupViewController:(UIViewController*)vc forViewKey:(NSString*)viewKey;

@end