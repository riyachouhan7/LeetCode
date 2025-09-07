/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function(n) {
    let res = [];
    
    if (n % 2 !== 0) {
        res.push(0);
    }

    for (let i = 1; i <= Math.floor(n / 2); i++) {
        res.push(i);
        res.push(-i);
    }

    return res;
};