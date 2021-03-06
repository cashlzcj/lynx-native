// Copyright 2017 The Lynx Authors. All rights reserved.

#include "base/ui_update_data_action.h"

@implementation LynxUIUpdateDataAction

- (id) initWithTarget:(RenderObjectImplBridge *)target andKey:(LynxRenderObjectAttr)key andData:(id)data {
    self = [super initWithType:DO_UPDATE_DATA_ACTION andTarget:target];
    if (self) {
        _key = key;
        _data = data;
    }
    return self;
}

- (void)doAction {
    [self.renderObjectImpl updateData:_data withKey:_key];
}

@end
