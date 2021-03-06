// Licensed to the Software Freedom Conservancy (SFC) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership. The SFC licenses this file
// to you under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef WEBDRIVER_IE_NEWSESSIONCOMMANDHANDLER_H_
#define WEBDRIVER_IE_NEWSESSIONCOMMANDHANDLER_H_

#include "../IECommandHandler.h"

namespace webdriver {

class NewSessionCommandHandler : public IECommandHandler {
 public:
  NewSessionCommandHandler(void);
  virtual ~NewSessionCommandHandler(void);

 protected:
  void ExecuteInternal(const IECommandExecutor& executor,
                       const ParametersMap& command_parameters,
                       Response* response);

 private:
  Json::Value GetCapability(Json::Value capabilities,
                            std::string capability_name,
                            Json::ValueType expected_capability_type,
                            Json::Value default_value);

  bool IsEquivalentType(Json::ValueType actual_type,
                        Json::ValueType expected_type);

  std::string GetJsonTypeDescription(Json::ValueType type);

  std::string GetUnexpectedAlertBehaviorValue(const std::string& desired_value);

  std::string GetPageLoadStrategyValue(const std::string& desired_value);
};

} // namespace webdriver

#endif // WEBDRIVER_IE_NEWSESSIONCOMMANDHANDLER_H_
