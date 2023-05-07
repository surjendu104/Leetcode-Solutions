/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let tmp = init;
    return {
        increment() {
            tmp++;
            return tmp;
        },
        decrement() {
            tmp--;
            return tmp;
        },
        reset() {
            tmp = init;
            return tmp;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */