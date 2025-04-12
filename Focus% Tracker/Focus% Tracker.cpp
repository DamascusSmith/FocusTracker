// Focus% Tracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>

int main()
{
	bool runClocks = true;
	bool isFocusActive = true;
	std::string input = "";
	//Tracking total clock
	auto startTime = std::chrono::steady_clock::now();
	//Tracking focus clock
	auto totalFocusTime = std::chrono::steady_clock::duration{ 0 };
	auto resumeFocusTime = std::chrono::steady_clock::now();

	while (runClocks)
	{
		if (isFocusActive)
		{
			std::cout << "Enter anything to pause: ";
		}
		else {
			std::cout << "Enter anything to resume: ";
		}
		std::cin >> input;
		if (input == "end")
		{	
			//Pause focus
			if (isFocusActive)
			{
				totalFocusTime += std::chrono::steady_clock::now() - resumeFocusTime;
				isFocusActive = false;
				std::cout << "Focus Pause\n";
			}

			//Stop total

			std::cout << "Total Clock Stopping\n";
			auto totalTime = std::chrono::steady_clock::now() - startTime;
			runClocks = false;

			//Output
			auto totalSeconds = std::chrono::duration_cast<std::chrono::seconds>(totalTime).count();
			auto focusSeconds = std::chrono::duration_cast<std::chrono::seconds>(totalFocusTime).count();
			
			//all gets formatted out
			int tH = totalSeconds / 3600;//just hours
			int tM = (totalSeconds % 3600) / 60;//will get what is leftover after hours
			int tS = totalSeconds % 60;//will get what is leftover after minutes
			int fH = focusSeconds / 3600;
			int fM = (focusSeconds % 3600) / 60;
			int fS = focusSeconds % 60;

			std::cout << "Total Time: ";
			std::cout << std::setfill('0') << std::setw(2) << tH << ":"
				<< std::setw(2) << tM << ":"
				<< std::setw(2) << tS << "\n";

			std::cout << "Focus Time: ";
			std::cout << std::setfill('0') << std::setw(2) << fH << ":"
				<< std::setw(2) << fM << ":"
				<< std::setw(2) << fS << "\n";
			float percentOfFocus = 100.0f * focusSeconds / totalSeconds;
			std::cout << std::fixed << std::setprecision(2) << "Focus % : " << percentOfFocus << "\n";

		}
		else if (input != "")
		{
			if (!isFocusActive)//starting
			{
				resumeFocusTime = std::chrono::steady_clock::now();
				isFocusActive = true;
				std::cout << "Focus Resumed\n";
			}
			else//pausing
			{
				totalFocusTime += std::chrono::steady_clock::now() - resumeFocusTime;
				isFocusActive = false;
				std::cout << "Focus Pause\n";
			}
			input = "";
		}
	}
	
	system("pause");
	return 0;
}


