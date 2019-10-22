//song.h
//Sam Brus and Collin Torok

class Song
{
    private:
        std::string title;
        std::string artist;
        int size;
    public:
        void setTitle(std::string);
        void setArtist(std::string);
        void setSize(int);

        std::string getTitle() const;
        std::string getArtist() const;
        int getSize() const;
};
