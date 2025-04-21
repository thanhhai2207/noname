<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use App\Models\Magazine;
use App\Models\Publisher;

class MagazineSeeder extends Seeder
{
    public function run(): void
    {
        $publishers = Publisher::all();

        if ($publishers->count() === 0) {
            $this->command->info("Không có nhà xuất bản nào, vui lòng seed PublisherSeeder trước.");
            return;
        }

        $topics = ['Khoa học', 'Văn học', 'Giáo dục', 'Thể thao', 'Công nghệ'];

        for ($i = 1; $i <= 10; $i++) {
            Magazine::create([
                'title' => 'Tạp chí số ' . $i,
                'issue_number' => 100 + $i,
                'release_date' => now()->subDays(rand(0, 100)),
                'topic' => $topics[array_rand($topics)],
                'publisher_id' => $publishers->random()->id,
            ]);
        }
    }
}

