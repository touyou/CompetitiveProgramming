use proconio::*;

fn main() {
    input! {
        n: usize,
        a: [i32; n]
    };

    let a_sum = a.iter().fold(0, |sum, a| sum + a);
    if a_sum % (n as i32) != 0 {
        println!("-1");
    } else {
        let opt_cnt = a_sum / (n as i32);
        let mut result = 0;
        let mut diff = a[0] - opt_cnt;
        let mut cnt = if diff == 0 { 0 } else { 1 };
        for i in 1..n {
            if opt_cnt != a[i] {
                diff += a[i] - opt_cnt;
            }
            if diff == 0 {
                result += cnt;
                cnt = 0;
            } else {
                cnt += 1;
            }
        }
        if cnt != 0 {
            result += cnt;
        }
        println!("{}", result);
    }
}
