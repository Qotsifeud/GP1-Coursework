#pragma once

struct ScreenBuffer {
public:
    ScreenBuffer() {};

    ScreenBuffer(int x, int y) : row(x), col(y) {
        m_buffer = new char* [row];
        for (int i = 0; i < row; ++i) {
            m_buffer[i] = new char[col];
        }
    };

    ~ScreenBuffer() {
        for (int i = 0; i < row; ++i) {
            delete[] m_buffer[i];
        }
        delete[] m_buffer;
    }

    ScreenBuffer(ScreenBuffer&& other) noexcept //Move Constructor
        : row(other.row), col(other.col), m_buffer(other.m_buffer)
    {
        // Reset the source object
        other.row = 0;
        other.col = 0;
        other.m_buffer = nullptr;
    }

    ScreenBuffer& operator=(ScreenBuffer&& other) noexcept //Move Assignment Operator
    {
        if (this != &other) {
            // Deallocate existing memory
            for (int i = 0; i < row; ++i) {
                delete[] m_buffer[i];
            }
            delete[] m_buffer;

            // Transfer ownership
            row = other.row;
            col = other.col;
            m_buffer = other.m_buffer;

            // Reset the source object
            other.row = 0;
            other.col = 0;
            other.m_buffer = nullptr;
        }
        return *this;
    }

    ScreenBuffer(const ScreenBuffer& other) : row(other.row), col(other.col) //Copy Constructor 
    {
        // Allocate memory for m_buffer
        m_buffer = new char* [row];
        for (int i = 0; i < row; ++i) {
            m_buffer[i] = new char[col];
        }

        // Copy the data from other to this object
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                m_buffer[i][j] = other.m_buffer[i][j];
            }
        }
    }

    ScreenBuffer& operator=(const ScreenBuffer& other) // Copy Assignment Operator
    {
        if (this == &other) {
            return *this;
        }

        // Deallocate existing memory
        for (int i = 0; i < row; ++i) {
            delete[] m_buffer[i];
        }
        delete[] m_buffer;

        // Allocate memory for new data
        row = other.row;
        col = other.col;
        m_buffer = new char* [row];
        for (int i = 0; i < row; ++i) {
            m_buffer[i] = new char[col];
        }

        // Copy the data from other to this object
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                m_buffer[i][j] = other.m_buffer[i][j];
            }
        }
        return *this;
    }

    char& getChar(int row, int col) {
        return m_buffer[row][col];
    }

    void setChar(int row, int col, char value) {
        m_buffer[row][col] = value;
    }

private:
    int row = 0;
    int col = 0;
    char** m_buffer = new char*;
};
