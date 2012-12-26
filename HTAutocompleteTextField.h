/* 
 * Copyright 2011 DoAT. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation and/or
 *    other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY DoAT “AS IS” WITHOUT ANY WARRANTIES WHATSOEVER. 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF NON INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
 * PARTICULAR PURPOSE ARE HEREBY DISCLAIMED. IN NO EVENT SHALL DoAT OR CONTRIBUTORS 
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of 
 * the authors and should not be interpreted as representing official policies, 
 * either expressed or implied, of DoAT.
 */

#import <UIKit/UIKit.h>
#import "HTDelegateProxy.h"

@class  HTAutocompleteTextField;

@protocol HTAutocompleteDataSource <UITextFieldDelegate>

- (NSString*)textField:(HTAutocompleteTextField*)textField
   completionForPrefix:(NSString*)prefix
            ignoreCase:(BOOL)ignoreCase;

@end

@interface HTAutocompleteTextField : UITextField <UITextFieldDelegate>

@property (nonatomic, strong) NSString *autocompleteString;
@property (nonatomic, strong) UIColor *autocompleteTextColor;
@property (nonatomic, assign) NSUInteger autocompleteType;
@property (nonatomic, assign) BOOL autocompleteDisabled;
@property (nonatomic, assign) BOOL ignoreCase;
@property (nonatomic, assign) CGPoint autocompleteTextOffset;

// autocompleteDataSource takes precedence over the GlobalDataSource setting
@property (nonatomic, assign) id autocompleteDataSource;

- (void)setDelegates:(NSArray *)delegates;
- (void)commitAutocompleteText;

// DefaultDataSource will be overridden if autocompleteDataSource is set.
+ (void)setDefaultAutocompleteDataSource:(id)dataSource;

// Override this method in a subclass to alter the position of the autocomplete text
- (CGRect)autocompleteRectForBounds:(CGRect)bounds;

@end