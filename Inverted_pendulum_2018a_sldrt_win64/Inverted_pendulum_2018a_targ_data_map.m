  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Inverted_pendulum_2018a_P)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Inverted_pendulum_2018a_P.K_realsetup
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Inverted_pendulum_2018a_P.Omega_c
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Inverted_pendulum_2018a_P.Q_interval
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Inverted_pendulum_2018a_P.T_s
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% Inverted_pendulum_2018a_P.V_max
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Inverted_pendulum_2018a_P.reference_State
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% Inverted_pendulum_2018a_P.AnalogOutput_FinalValue
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% Inverted_pendulum_2018a_P.AnalogOutput_InitialValue
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% Inverted_pendulum_2018a_P.AnalogInput_MaxMissedTicks
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% Inverted_pendulum_2018a_P.AnalogOutput_MaxMissedTicks
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% Inverted_pendulum_2018a_P.AnalogInput_YieldWhenWaiting
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 16;
	
	  ;% Inverted_pendulum_2018a_P.AnalogOutput_YieldWhenWaiting
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% Inverted_pendulum_2018a_P.AnalogInputsInvertedPendulum_offset_alfa
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% Inverted_pendulum_2018a_P.AnalogInputsInvertedPendulum_offset_x
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% Inverted_pendulum_2018a_P.AnalogInputsInvertedPendulum_v2m
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% Inverted_pendulum_2018a_P.AnalogInputsInvertedPendulum_v2r
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Inverted_pendulum_2018a_P.AnalogInput_Channels
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Inverted_pendulum_2018a_P.AnalogOutput_Channels
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Inverted_pendulum_2018a_P.AnalogInput_RangeMode
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Inverted_pendulum_2018a_P.AnalogOutput_RangeMode
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Inverted_pendulum_2018a_P.AnalogInput_VoltRange
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Inverted_pendulum_2018a_P.AnalogOutput_VoltRange
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Inverted_pendulum_2018a_P.Constant5_Value
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Inverted_pendulum_2018a_P.Constant4_Value
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Inverted_pendulum_2018a_P.Off_Value
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 8;
	
	  ;% Inverted_pendulum_2018a_P.UnitDelay_InitialCondition
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 9;
	
	  ;% Inverted_pendulum_2018a_P.UnitDelay_InitialCondition_l
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 10;
	
	  ;% Inverted_pendulum_2018a_P.UnitDelay_InitialCondition_b
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 11;
	
	  ;% Inverted_pendulum_2018a_P.UnitDelay_InitialCondition_m
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 12;
	
	  ;% Inverted_pendulum_2018a_P.uvto5v_UpperSat
	  section.data(8).logicalSrcIdx = 29;
	  section.data(8).dtTransOffset = 13;
	
	  ;% Inverted_pendulum_2018a_P.uvto5v_LowerSat
	  section.data(9).logicalSrcIdx = 30;
	  section.data(9).dtTransOffset = 14;
	
	  ;% Inverted_pendulum_2018a_P.Gain_Gain
	  section.data(10).logicalSrcIdx = 31;
	  section.data(10).dtTransOffset = 15;
	
	  ;% Inverted_pendulum_2018a_P.Gain_Gain_b
	  section.data(11).logicalSrcIdx = 32;
	  section.data(11).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Inverted_pendulum_2018a_P.Switch2_CurrentSetting
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Inverted_pendulum_2018a_P.Switch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Inverted_pendulum_2018a_P.Switch_CurrentSetting
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Inverted_pendulum_2018a_B)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% Inverted_pendulum_2018a_B.Convertionactor
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Inverted_pendulum_2018a_B.Add
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Inverted_pendulum_2018a_B.Convertion
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Inverted_pendulum_2018a_B.Add_k
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Inverted_pendulum_2018a_B.Gain2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Inverted_pendulum_2018a_B.Gain2_o
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Inverted_pendulum_2018a_B.Switch1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Inverted_pendulum_2018a_B.Gain1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% Inverted_pendulum_2018a_B.Switch
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% Inverted_pendulum_2018a_B.RateTransition1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% Inverted_pendulum_2018a_B.Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% Inverted_pendulum_2018a_B.RateTransition
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Inverted_pendulum_2018a_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Inverted_pendulum_2018a_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_j
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_n
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_o
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Inverted_pendulum_2018a_DW.AnalogInput_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Inverted_pendulum_2018a_DW.AnalogOutput_PWORK
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Inverted_pendulum_2018a_DW.HiddenToAsyncQueue_InsertedFor_AnalogInputsInvertedPendulum_at_outport_0_PWORK.AQHandles
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Inverted_pendulum_2018a_DW.HiddenToAsyncQueue_InsertedFor_AnalogInputsInvertedPendulum_at_outport_1_PWORK.AQHandles
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Inverted_pendulum_2018a_DW.HiddenToAsyncQueue_InsertedFor_Switch1_at_outport_0_PWORK.AQHandles
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Inverted_pendulum_2018a_DW.HiddenToAsyncQueue_InsertedFor_Switch_at_outport_0_PWORK.AQHandles
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Inverted_pendulum_2018a_DW.OUTPUT1_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Inverted_pendulum_2018a_DW.OUTPUT2_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Inverted_pendulum_2018a_DW.Scope2_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2416031737;
  targMap.checksum1 = 640436642;
  targMap.checksum2 = 529683781;
  targMap.checksum3 = 2466065626;

