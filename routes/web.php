<?php
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\MagazineController;



Route::get('/', [MagazineController::class, 'index'])->name('magazines.index');


Route::get('/magazines/{id}', [MagazineController::class, 'show'])->name('magazines.show');
Route::post('/magazines/store', [MagazineController::class, 'store'])->name('magazines.store');
Route::get('/magazines/create', [MagazineController::class, 'create'])->name('magazines.create');

