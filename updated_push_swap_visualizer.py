
import pygame
import sys
import time

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

    def get_items(self):
        return self.items

class StackVisualizer:
    def __init__(self, numbers):
        self.stack_a = Stack()
        self.stack_b = Stack()
        for num in numbers:
            self.stack_a.push(num)

        self.operation_mapping = {
            'sa': self.swap_a,
            'sb': self.swap_b,
            'ss': self.swap_both,
            'pa': self.push_a,
            'pb': self.push_b,
            'ra': self.rotate_a,
            'rb': self.rotate_b,
            'rr': self.rotate_both,
            'rra': self.reverse_rotate_a,
            'rrb': self.reverse_rotate_b,
            'rrr': self.reverse_rotate_both
        }
        # Initialize Pygame
        pygame.init()
        self.screen_width = 800
        self.screen_height = 600
        self.screen = pygame.display.set_mode((self.screen_width, self.screen_height))
        self.base_stack_height = self.screen_height // 2

    # ... (existing operation methods) ...

    def draw_stack(self, stack, offset_x):
        items = stack.get_items()
        for i, item in enumerate(items):
            rect_height = (self.screen_height // 2) // (max(items) + 1) * item
            rect_width = self.screen_width // len(items) - 10
            pygame.draw.rect(self.screen, (255, 255, 255), (
                offset_x + i * (rect_width + 10), self.base_stack_height - rect_height, rect_width, rect_height))

    def draw(self):
        self.screen.fill((0, 0, 0))  # Fill the screen with black color
        self.draw_stack(self.stack_a, 10)
        self.draw_stack(self.stack_b, self.screen_width // 2 + 10)
        pygame.display.flip()  # Update the full display Surface to the screen

    def run(self, operations):
        # Main loop
        running = True
        for operation in operations:
            if operation in self.operation_mapping:
                self.operation_mapping[operation]()
                self.draw()
                time.sleep(0.5)  # Pause for half a second to visualize the operation

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    pygame.quit()
                    sys.exit()

if __name__ == "__main__":
    # Initialize stack numbers directly in the script
    numbers = [7, 6, 5, 4, 3, 2, 1]  # Modify this line with your stack numbers

    # Read operations from standard input (piped from push_swap output)
    operations = sys.stdin.read().strip().split('\n')

    visualizer = StackVisualizer(numbers)
    visualizer.run(operations)
