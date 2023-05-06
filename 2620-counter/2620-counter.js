/**
 * @param {number} n
 * @return {Function} counter
 */

var createCounter = function(n) {
    let tmp = n-1;
    return function() {
        tmp++;
        return tmp;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */