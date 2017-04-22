#ifndef InputFile_h
#define InputFile_h

class InputFile
{
    friend InputFile& operator>>(InputFile& fin, int a)
    {
        fin.input_stream >> a;
        return fin;
    }
    
public:
    InputFile(const std::string& filename) : input_stream(filename)
    {
        if (input_stream.fail())
        {
            std::cout << "Error opening: " << filename << std::endl;
        }
    }
    
    ~InputFile()
    {
        input_stream.close();
    }
    
private:
    std::ifstream input_stream;
};



#endif /* InputFile_h */
