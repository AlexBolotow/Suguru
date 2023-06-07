#pragma once

class Theme {
public:
	enum ThemeState {
		Dark,
		Light
	};

	ThemeState getThemeState();
	void setThemeState(ThemeState themeState);

private:
	ThemeState themeState{};
};