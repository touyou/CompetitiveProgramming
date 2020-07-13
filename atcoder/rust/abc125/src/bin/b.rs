use proconio::*;

fn main() {
    input! {
        n: usize,
        mut v: [i32; n],
        c: [i32; n]
    };
    for i in 0..n {
        v[i] -= c[i];
    }
    v.sort();
    v.reverse();
    println!("{}", v.iter().filter(|&x| x.is_positive()).fold(0, |acc, x| acc + x));
}
