/* -*- mode:c++; indent-tabs-mode: nil -*-
 * Copyright (c) 2004, Technische Universitaet Berlin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright 
 *   notice, this list of conditions and the following disclaimer in the 
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the Technische Universitaet Berlin nor the names 
 *   of its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY 
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE 
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
 
 /**
 * Configuration for the fixed Rssi Threshold module.
 *
 * @author: Kevin Klues (klues@tkn.tu-berlin.de)
 * @author: Andreas Koepke (koepke@tkn.tu-berlin.de)
 */
configuration RssiFixedThresholdCMC
{
    provides {
        interface StdControl;
        interface ChannelMonitor;
        interface ChannelMonitorControl;
        interface ChannelMonitorData;
        interface BatteryLevel;
        interface Resource as RssiAdcResource;
    }    
}
implementation
{
    components RssiFixedThresholdCMP,
        RssiSensorVccC as Rssi,
        new BatteryLevelSensorC() as Voltage,
        new TimerMilliC() as Timer,
        MainC;

    MainC.SoftwareInit -> RssiFixedThresholdCMP;
    StdControl = RssiFixedThresholdCMP;
    RssiAdcResource = Rssi;
    
    RssiFixedThresholdCMP.Rssi -> Rssi;
    RssiFixedThresholdCMP.Voltage -> Voltage;

    ChannelMonitor = RssiFixedThresholdCMP;
    ChannelMonitorControl = RssiFixedThresholdCMP;
    ChannelMonitorData = RssiFixedThresholdCMP;
    BatteryLevel = RssiFixedThresholdCMP;

/*    components PlatformLedsC;
    RssiFixedThresholdCMP.Led3 -> PlatformLedsC.Led3;
    RssiFixedThresholdCMP.Led2 -> PlatformLedsC.Led2;
*/
    RssiFixedThresholdCMP.Timer -> Timer;    
}
