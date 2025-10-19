#ifndef TRAYICON_H
#define TRAYICON_H

#include <windows.h>
#include <shellapi.h>

class TrayIcon {
public:
    TrayIcon(HINSTANCE hInstance, HWND hWnd);
    ~TrayIcon();
    void addToTray();
    void removeFromTray();
    void hideWindow();
    void showWindow();
    void createContextMenu();
    void handleContextMenu(int command);
    void showNotification(const char* title, const char* message);

private:
    HINSTANCE hInstance;
    HWND hWnd;
    NOTIFYICONDATA nid;
};

#endif // TRAYICON_H