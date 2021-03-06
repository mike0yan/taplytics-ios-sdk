//
//  TLBarButtonItem.h
//  Taplytics
//
//  Copyright (c) 2014 Syrp Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TLElementProtocol.h"

@interface TLBarButtonItem : UIBarButtonItem <TLElementProtocol>

- (id)initWithElementKey:(NSString*)elementKey styleKey:(NSString*)styleKey;

- (id)initWithImage:(UIImage *)image style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action
                 elementKey:(NSString*)elementKey styleKey:(NSString*)styleKey;

- (id)initWithImage:(UIImage *)image landscapeImagePhone:(UIImage *)landscapeImagePhone style:(UIBarButtonItemStyle)style
                       target:(id)target action:(SEL)action elementKey:(NSString*)elementKey styleKey:(NSString*)styleKey;

- (id)initWithTitle:(NSString *)title style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action
                 elementKey:(NSString*)elementKey styleKey:(NSString*)styleKey;

- (id)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem target:(id)target action:(SEL)action
                               elementKey:(NSString*)elementKey styleKey:(NSString*)styleKey;

- (id)initWithCustomView:(UIView *)customView elementKey:(NSString*)elementKey styleKey:(NSString*)styleKey;

@property (nonatomic, strong) NSString* testString;

@end
