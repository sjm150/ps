use std::io::{self, Read};
use std::cmp;

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let k: u32 = input.next().unwrap().parse().unwrap();

    let mut max_area = 0;
    let mut sub_area = 0;

    let first_direction: u32;
    let first_length: u32;
    let mut prev_direction: u32;
    let mut prev_length: u32;
    let mut temp_direction: u32;
    let mut temp_length: u32;

    first_direction = input.next().unwrap().parse().unwrap();
    first_length = input.next().unwrap().parse().unwrap();
    prev_direction = first_direction;
    prev_length = first_length;

    for _i in 1..6 {
        temp_direction = input.next().unwrap().parse().unwrap();
        temp_length = input.next().unwrap().parse().unwrap();

        match prev_direction {
            1 => {
                match temp_direction {
                    4 => max_area = cmp::max(max_area, prev_length * temp_length),
                    3 => sub_area = prev_length * temp_length,
                    _ => (),
                }
            }
            2 => {
                match temp_direction {
                    3 => max_area = cmp::max(max_area, prev_length * temp_length),
                    4 => sub_area = prev_length * temp_length,
                    _ => (),
                }
            }
            3 => {
                match temp_direction {
                    1 => max_area = cmp::max(max_area, prev_length * temp_length),
                    2 => sub_area = prev_length * temp_length,
                    _ => (),
                }
            }
            4 => {
                match temp_direction {
                    2 => max_area = cmp::max(max_area, prev_length * temp_length),
                    1 => sub_area = prev_length * temp_length,
                    _ => (),
                }
            }
            _ => (),
        }

        prev_direction = temp_direction;
        prev_length = temp_length;
    }

    temp_direction = first_direction;
    temp_length = first_length;
    match prev_direction {
        1 => {
            match temp_direction {
                4 => max_area = cmp::max(max_area, prev_length * temp_length),
                3 => sub_area = prev_length * temp_length,
                _ => (),
            }
        }
        2 => {
            match temp_direction {
                3 => max_area = cmp::max(max_area, prev_length * temp_length),
                4 => sub_area = prev_length * temp_length,
                _ => (),
            }
        }
        3 => {
            match temp_direction {
                1 => max_area = cmp::max(max_area, prev_length * temp_length),
                2 => sub_area = prev_length * temp_length,
                _ => (),
            }
        }
        4 => {
            match temp_direction {
                2 => max_area = cmp::max(max_area, prev_length * temp_length),
                1 => sub_area = prev_length * temp_length,
                _ => (),
            }
        }
        _ => (),
    }

    println!("{}", k * (max_area - sub_area));
}
