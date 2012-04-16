/*********************************************************************************
* Copyright (c) 2010-2011, 
* Jim Stevens, Paul Tschirhart, Ishwar Singh Bhati, Mu-Tien Chang, Peter Enns, 
* Elliott Cooper-Balis, Paul Rosenfeld, Bruce Jacob
* University of Maryland
* Contact: jims [at] cs [dot] umd [dot] edu
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*********************************************************************************/


#ifndef PCI_SSD_SYSTEM_H
#define PCI_SSD_SYSTEM_H

#include "CallbackPCI.h"

#include "config.h"

namespace PCISSD
{
	class PCI_SSD_System
	{
		public:
		PCI_SSD_System(uint id);
		bool addTransaction(bool isWrite, uint64_t addr);
		bool WillAcceptTransaction();
		void update();
		void RegisterCallbacks(TransactionCompleteCB *readDone, TransactionCompleteCB *writeDone);
		void printLogfile();

		// Internal functions
		void HybridSim_Read_Callback(uint id, uint64_t addr, uint64_t cycle);
		void HybridSim_Write_Callback(uint id, uint64_t addr, uint64_t cycle);


		// Internal state
        TransactionCompleteCB *ReadDone;
        TransactionCompleteCB *WriteDone;
		uint systemID;

		uint64_t currentClockCycle;

		HybridSim::HybridSystem *hybridsim;

	};

	PCI_SSD_System *getInstance(uint id);

}

#endif
