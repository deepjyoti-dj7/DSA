def trap(height):
    if not height:
        return 0

    left, right = 0, len(height) - 1
    left_max, right_max, water = 0, 0, 0

    while left < right:
        if height[left] < height[right]:
            if height[left] >= left_max:
                left_max = height[left]
            else:
                water += left_max - height[left]
            left += 1
        else:
            if height[right] >= right_max:
                right_max = height[right]
            else:
                water += right_max - height[right]
            right -= 1

    return water

# Main function
def main():
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    print("Trapped water:", trap(height))

# Run main function
if __name__ == "__main__":
    main()
