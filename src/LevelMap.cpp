#include <LevelMap.h>

LevelMap::LevelMap()
{
    readMapsFile();
}

LevelMap::~LevelMap()
{}

void LevelMap::readMapsFile()
{
    std::string rows2, cols2;
    int rows, cols;
    std::ifstream boardFile;
    boardFile.open(BoardTxt);

    std::string str;

    


    while (!boardFile.eof())
    {
        boardFile >> rows >> cols;
        if (rows < 0 || rows > 28 || cols < 0 || cols > 32)
        {
            std::cerr << "Board file is out of range, please put levels with max 28 rows and 32 cols" << std::endl;
            exit(EXIT_FAILURE);
        }

        std::vector<std::string> LevelMap;
        boardFile.get();
        boardFile.get();
        
        for (int i = 0; i < rows; i++)
        {
            getline(boardFile, str);
            LevelMap.push_back(str);
        }
        m_levelMap.push_back(LevelMap);

    }

    boardFile.close();
}

size_t LevelMap::getnumOfLevel() const
{
    return m_levelMap.size();
}

std::vector<std::string> LevelMap::operator[](int level) const
{
    return m_levelMap[level];
}
