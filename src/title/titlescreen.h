#pragma once
#include <memory>
#include <vector>
#include <string>

class title_screen {
private:
	static std::unique_ptr<title_screen> s_title_singleton;
	std::vector<std::string> s_savefiles;
	std::string savefile_name;
	bool autosave;
	bool titleInitiated;
	void choose_savefile_name();
	void selectAndLoadSaveFile();
public:
	static title_screen& getInstance();
	void mode_title();
	std::string_view getFileName() const noexcept;
	void reset();
	void setautosaveoption(bool shouldautosave);
	void autosavegame();
};
/*
 titlescreen.cpp
*/
//void mode_title();
