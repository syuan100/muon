// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE-CHROMIUM file.

#ifndef BRIGHTRAY_BROWSER_BROWSER_MAIN_PARTS_H_
#define BRIGHTRAY_BROWSER_BROWSER_MAIN_PARTS_H_

#include "base/compiler_specific.h"
#include "base/memory/ref_counted.h"
#include "content/public/browser/browser_main_parts.h"

#if defined(TOOLKIT_VIEWS)
namespace brightray {
class ViewsDelegate;
}
namespace views {
class LayoutProvider;
}
#endif

#if defined(USE_AURA) && defined(USE_X11)
namespace wm {
class WMState;
}
#endif

namespace brightray {

class BrowserMainParts : public content::BrowserMainParts {
 public:
  BrowserMainParts();
  ~BrowserMainParts();

 protected:
  // content::BrowserMainParts:
  void PreEarlyInitialization() override;
  void ToolkitInitialized() override;
  void PreMainMessageLoopStart() override;
  void PreMainMessageLoopRun() override;
  void PostMainMessageLoopStart() override;
  void PostMainMessageLoopRun() override;
  void PostDestroyThreads() override;

 private:
#if defined(OS_MACOSX)
  void InitializeMainNib();
#endif

#if defined(TOOLKIT_VIEWS)
  std::unique_ptr<ViewsDelegate> views_delegate_;
  std::unique_ptr<views::LayoutProvider> layout_provider_;
#endif

#if defined(USE_AURA) && defined(USE_X11)
  std::unique_ptr<wm::WMState> wm_state_;
#endif

  DISALLOW_COPY_AND_ASSIGN(BrowserMainParts);
};

}  // namespace brightray

#endif
