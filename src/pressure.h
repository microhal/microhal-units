/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief      pressure unit
 *
 * @authors    Pawel
 * created on: 12 lis 2015
 * last modification: 12 lis 2015
 *
 * @copyright Copyright (c) 2015, microHAL
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * 	   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
 * 	      documentation and/or other materials provided with the distribution.
 *     3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this
 *        software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _MICROHAL_PRESSURE_H_
#define _MICROHAL_PRESSURE_H_

namespace microhal {

template <typename T = float>
class Pressure {
 public:
    explicit Pressure(T pressure) : pressure(pressure) {}
    Pressure() = default;

    T getRAW() const { return pressure; }

 private:
    T pressure;
};

template <microhal::diagnostic::LogLevel level, bool B, typename T>
inline microhal::diagnostic::LogLevelChannel<level, B> operator<<(microhal::diagnostic::LogLevelChannel<level, B> logChannel,
                                                                  const Pressure<T>& pressure) {
    return logChannel << pressure.getRAW() << " Pa";
}

}  // namespace microhal

#endif  // _MICROHAL_PRESSURE_H_
