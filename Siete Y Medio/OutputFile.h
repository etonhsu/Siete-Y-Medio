#ifndef OutputFile_h
#define OutputFile_h

class OutputFile
{
    friend OutputFile& operator<<(OutputFile& fout, const char* a)
    {
        fout.output_stream << a;
        return fout;
    }
    
    
    friend OutputFile& operator<<(OutputFile& fout, int a)
    {
        fout.output_stream << a;
        return fout;
    }
    
    friend OutputFile& operator<<(OutputFile& fout, char*)
    {
        fout.output_stream << "\n";
        return fout;
    }
    
    
public:
    OutputFile(const std::string& filename) : output_stream(filename) {}
    ~OutputFile () {output_stream.close();}
    
private:
    std::ofstream output_stream;
};


#endif /* OutputFile_h */
