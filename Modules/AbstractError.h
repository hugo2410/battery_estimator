//
// Created by hugo on 10/11/2022.
//

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <exception>
#include <iostream>

/**
 * \brief Abstract Error Class to Manage all errors encountered by the program.
 */
class AbstractError : public std::exception {
protected:

public:
    /**
     * \brief Default Constructor.
     */
    explicit
    AbstractError() {}

    /** \brief Default Destructor.
     *  Virtual to allow for subclassing.
     */
    virtual ~AbstractError() throw () {}

    /**
     * \brief Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *  is in possession of the AbstractError object. Callers must
     *  not attempt to free the memory.
     */
    virtual const char * what () const throw ()  {
        std::cerr<<"An exception was thrown!"<< std::endl;
        return "Error!";
    }

};

struct WindError : public AbstractError{
    const char * what () const throw () override {
        return "Wind speed greater than cruise speed, drone is going backwards!";
    }
};

#endif /* ERROR_HPP_*/