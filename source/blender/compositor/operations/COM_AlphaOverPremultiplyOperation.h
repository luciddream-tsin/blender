/* SPDX-FileCopyrightText: 2011 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "COM_MixOperation.h"

namespace blender::compositor {

/**
 * this program converts an input color to an output value.
 * it assumes we are in sRGB color space.
 */
class AlphaOverPremultiplyOperation : public MixBaseOperation {
 public:
  AlphaOverPremultiplyOperation();

  void update_memory_buffer_row(PixelCursor &p) override;
};

}  // namespace blender::compositor
