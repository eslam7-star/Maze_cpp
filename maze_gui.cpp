#pragma once
#include "olcPixelGameEngine.h"

class MazeGUI : public olc::PixelGameEngine
{
public:
    MazeGUI()
    {
        sAppName = "Maze GUI Example";
    }

    bool OnUserCreate() override
    {
        // Load your maze data or generate it dynamically
        LoadMaze();

        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        // Handle user input, update game logic, etc.
        HandleInput();

        // Render the maze
        DrawMaze();

        return true;
    }

private:
    // Define maze dimensions and data
    static constexpr int nMazeWidth = 10;
    static constexpr int nMazeHeight = 10;
    int mazeData[nMazeHeight][nMazeWidth] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    void LoadMaze()
    {
        // Load or generate your maze data
    }

    void HandleInput()
    {
        // Handle user input, e.g., arrow keys, WASD, etc.
    }

    void DrawMaze()
    {
        // Clear the screen
        Clear(olc::Pixel(0, 0, 0));

        // Draw the maze based on mazeData
        for (int y = 0; y < nMazeHeight; y++)
        {
            for (int x = 0; x < nMazeWidth; x++)
            {
                // Draw walls in white and paths in black
                olc::Pixel color = (mazeData[y][x] == 1) ? olc::WHITE : olc::BLACK;
                FillRect(x * 20, y * 20, 20, 20, color);
            }
        }
    }
};
