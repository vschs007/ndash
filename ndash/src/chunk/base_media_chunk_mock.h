/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NDASH_CHUNK_BASE_MEDIA_CHUNK_MOCK_H_
#define NDASH_CHUNK_BASE_MEDIA_CHUNK_MOCK_H_

#include <cstdint>

#include "chunk/base_media_chunk.h"
#include "drm/drm_init_data.h"
#include "gmock/gmock.h"
#include "media_format.h"
#include "upstream/data_spec.h"

namespace ndash {

class MediaFormat;

namespace drm {
class DrmInitDataInterface;
}  // namespace drm

namespace util {
class Format;
}  // namespace util

namespace chunk {

class MockBaseMediaChunk : public BaseMediaChunk {
 public:
  MockBaseMediaChunk(const upstream::DataSpec* data_spec,
                     TriggerReason trigger,
                     const util::Format* format,
                     int64_t start_time_us,
                     int64_t end_time_us,
                     int chunk_index,
                     bool is_media_format_final,
                     int parent_id);
  ~MockBaseMediaChunk() override;

  // BaseMediaChunk
  MOCK_CONST_METHOD0(GetMediaFormat, const MediaFormat*());
  MOCK_CONST_METHOD0(GetDrmInitData,
                     scoped_refptr<const drm::RefCountedDrmInitData>());

  // MediaChunk has no virtual methods

  // Chunk
  MOCK_CONST_METHOD0(GetNumBytesLoaded, int64_t());

  // Loadable
  MOCK_METHOD0(CancelLoad, void());
  MOCK_CONST_METHOD0(IsLoadCanceled, bool());
  MOCK_METHOD0(Load, bool());
};

}  // namespace chunk
}  // namespace ndash

#endif  // NDASH_CHUNK_BASE_MEDIA_CHUNK_MOCK_H_
