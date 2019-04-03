#ifndef UPDATABLE_HPP
#define UPDATABLE_HPP


class Updatable {
public:
    Updatable() = default;
    virtual ~Updatable() = default;
    Updatable(Updatable const &) = delete;
    Updatable(Updatable &&) = delete;
    Updatable & operator=(Updatable const &) = delete;
    Updatable & operator=(Updatable &&) = delete;

    virtual void update() = 0;
};


#endif // UPDATABLE_HPP
