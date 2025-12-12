export function averageWeight(w: number[], l: any): number {
    let s = 0;
    for (let i = 0; i < l; i++) {
        s += w[i];
    }
    return s / l;
}

const weights1: number[] = [2, 5, 7, 10];
const weights2: number[] = [2];

console.log(`Average weight for 4 gifts: ${averageWeight(weights1, 4).toFixed(2)}`);
console.log(`Average weight for 1 gift: ${averageWeight(weights2, 1).toFixed(2)}`);