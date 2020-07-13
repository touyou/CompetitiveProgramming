use proconio::*;

fn is_month(n: u32) -> bool {
    return n >= 1 && n <= 12;
}

fn main() {
    input! {
        s: u32
    };
    let bef = s / 100;
    let aft = s % 100;
    if is_month(bef) && is_month(aft) {
        println!("AMBIGUOUS");
    } else if is_month(bef) {
        println!("MMYY");
    } else if is_month(aft) {
        println!("YYMM");
    } else {
        println!("NA");
    }
}
